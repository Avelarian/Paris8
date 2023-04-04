-- CreateTable
CREATE TABLE "Document" (
    "id" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    "filename" TEXT NOT NULL
);

-- CreateTable
CREATE TABLE "Word" (
    "id" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    "word" TEXT NOT NULL
);

-- CreateTable
CREATE TABLE "WordsOnDocuments" (
    "documentId" INTEGER NOT NULL,
    "wordId" INTEGER NOT NULL,

    PRIMARY KEY ("documentId", "wordId"),
    CONSTRAINT "WordsOnDocuments_documentId_fkey" FOREIGN KEY ("documentId") REFERENCES "Document" ("id") ON DELETE RESTRICT ON UPDATE CASCADE,
    CONSTRAINT "WordsOnDocuments_wordId_fkey" FOREIGN KEY ("wordId") REFERENCES "Word" ("id") ON DELETE RESTRICT ON UPDATE CASCADE
);
