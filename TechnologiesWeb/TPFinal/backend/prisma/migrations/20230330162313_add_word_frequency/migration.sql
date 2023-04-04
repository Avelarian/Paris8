/*
  Warnings:

  - Added the required column `wordFrequency` to the `WordsOnDocuments` table without a default value. This is not possible if the table is not empty.

*/
-- RedefineTables
PRAGMA foreign_keys=OFF;
CREATE TABLE "new_WordsOnDocuments" (
    "wordFrequency" INTEGER NOT NULL,
    "documentId" INTEGER NOT NULL,
    "wordId" INTEGER NOT NULL,

    PRIMARY KEY ("documentId", "wordId"),
    CONSTRAINT "WordsOnDocuments_documentId_fkey" FOREIGN KEY ("documentId") REFERENCES "Document" ("id") ON DELETE RESTRICT ON UPDATE CASCADE,
    CONSTRAINT "WordsOnDocuments_wordId_fkey" FOREIGN KEY ("wordId") REFERENCES "Word" ("id") ON DELETE RESTRICT ON UPDATE CASCADE
);
INSERT INTO "new_WordsOnDocuments" ("documentId", "wordId") SELECT "documentId", "wordId" FROM "WordsOnDocuments";
DROP TABLE "WordsOnDocuments";
ALTER TABLE "new_WordsOnDocuments" RENAME TO "WordsOnDocuments";
PRAGMA foreign_key_check;
PRAGMA foreign_keys=ON;
