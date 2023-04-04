import { Injectable } from '@nestjs/common';
import { PrismaService } from './prisma/prisma.service';
import { join } from 'path';
import { readFileSync } from 'fs';

import { readTextFilesRecursively } from './utils';

const DOCUMENTS_DIRECTORY_PATH = join(__dirname, '../documents');

@Injectable()
export class AppService {
  constructor(private readonly prisma: PrismaService) {}

  stopwords = readFileSync(join(__dirname, '../stopwords.txt'), 'utf8').split(
    '\n',
  );

  async readFile(file: string) {
    const content = readFileSync(file, 'utf8');
    const newDocument = await this.prisma.document.create({
      data: { filename: file },
    });

    const tokens = content
      .normalize('NFD')
      .replace(/[\u0300-\u036f]/g, '')
      .split(/[ ,.'!]+/)
      .map((word) => word.toLowerCase());
    const filteredTokens = tokens.filter(
      (token) => !this.stopwords.includes(token) && token.length > 1,
    );

    const frequencyMap = new Map();
    for (const token of filteredTokens) {
      frequencyMap.set(token, (frequencyMap.get(token) || 0) + 1);
    }

    const wordsToAdd = [];
    const frequencyToAdd = [];
    frequencyMap.forEach((value: boolean, key: string) => {
      wordsToAdd.push(key);
      frequencyToAdd.push(value);
    });

    for (const x of wordsToAdd) {
      const isWordAlredyInBd = await this.prisma.word.findMany({
        where: { word: x },
      });

      let newWord;
      if (isWordAlredyInBd.length === 0) {
        newWord = await this.prisma.word.create({ data: { word: x } });
      }

      await this.prisma.wordsOnDocuments.create({
        data: {
          documentId: newDocument.id,
          wordId: newWord?.id ?? isWordAlredyInBd[0].id,
          wordFrequency: frequencyMap.get(x),
        },
      });
    }
    return;
  }

  async updateBd() {
    const files = readTextFilesRecursively(DOCUMENTS_DIRECTORY_PATH);
    const filenames = (
      await this.prisma.document.findMany({
        select: { filename: true },
      })
    ).map((document) => document.filename);

    for (const file of files) {
      if (!filenames.includes(file)) {
        await this.readFile(file);
      }
    }
  }

  async search(query: string) {
    const formattedQuery = query
      .normalize('NFD')
      .replace(/[\u0300-\u036f]/g, '')
      .split(/[ ,.'!]+/)
      .map((word) => word.toLowerCase());

    const filter = formattedQuery.reduce((acc, word) => {
      return acc.concat([
        {
          word: { startsWith: word },
        },
        {
          word: { endsWith: word },
        },
        {
          word: { in: word },
        },
        {
          word: { contains: word },
        },
      ]);
    }, []);
    const results = await this.prisma.word.findMany({
      where: {
        OR: filter,
      },
      include: { documents: true },
    });

    const documentIds = results.reduce((acc, result) => {
      return acc.concat(
        result.documents.map((document) => document.documentId),
      );
    }, []);

    const documents = await this.prisma.document.findMany({
      where: { id: { in: documentIds } },
    });

    return documents.reduce((acc, document) => {
      return acc.concat([
        {
          document: document.filename,
          words: results
            .map((result) => {
              if (
                result.documents
                  .map((resultDocument) => resultDocument.documentId)
                  .includes(document.id)
              )
                return {
                  word: result.word,
                  frequency: result.documents.find(
                    (relation) => relation.documentId === document.id,
                  ).wordFrequency,
                };
            })
            .filter((word) => word),
        },
      ]);
    }, []);
  }

  findAllDocuments() {
    return this.prisma.document.findFirst({ where: { id: 10 } });
  }

  findAllWords() {
    return this.prisma.word.findMany();
  }
}
