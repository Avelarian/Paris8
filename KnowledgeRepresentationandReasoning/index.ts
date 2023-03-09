const connectors = ["AND", "OR", "NOT", "IF", "THEN", "IFF"];

const senteceExamples = [
  "P AND Q",
  "R OR S",
  "NOT P",
  "IF P THEN Q",
  "P IFF Q",
  "NOT R OR S",
  "P AND NOT Q",
  "NOT (P OR Q)",
  "IF NOT P THEN Q",
  "P IFF NOT Q",
  "NOT (R AND S)",
  "P OR NOT Q",
  "IF P OR Q THEN R",
  "P IFF R OR S",
  "NOT (P AND Q)",
  "R AND NOT S",
  "NOT (P AND R) OR Q",
  "P IFF Q",
  "NOT (P OR R) AND S",
  "P OR Q AND R",
  "IF P AND Q THEN R AND S",
  "P IFF NOT (Q OR R)",
  "NOT P OR NOT Q",
  "P IF Q THEN R",
  "P IFF NOT (Q AND R)",
  "NOT P OR Q",
  "IF P AND Q AND R THEN S",
  "P OR NOT (Q AND R)",
  "P IF NOT Q OR R",
  "P IFF Q AND NOT R",
  "NOT (P AND Q AND R)",
  "R AND NOT (S OR T)",
  "IF P THEN Q OR R",
  "P IFF (Q OR R) AND NOT S",
  "NOT (P IF Q)",
  "R OR NOT (S AND T)",
  "IF P OR Q OR R THEN S OR T",
  "P IFF NOT (Q IFF R)",
  "NOT (P OR Q OR R)",
  "NOT R OR (S AND T)",
  "IF P AND Q OR R THEN S AND T",
  "P IFF Q IFF NOT R",
  "NOT (P AND Q OR R)",
  "R AND NOT (S IF T)",
  "IF P OR Q AND R THEN S OR T",
  "P IFF NOT (Q IFF NOT R)",
  "NOT (P OR Q AND R)",
  "NOT R AND (S OR NOT T)",
  "IF P AND NOT Q THEN R OR S",
];

const nonSentenceExamples = [
  "AND OR NOT IF THEN IFF",
  "3 AND 5",
  "x OR NOT",
  "IF THEN",
  "NOT OR",
  "AND OR IF",
  "OR OR OR",
  "NOT IF",
  "IF AND OR THEN",
  "NOT NOT NOT",
  "OR AND THEN",
  "IF THEN AND OR",
  "NOT IF THEN",
  "AND OR OR",
  "THEN AND",
  "IF AND THEN",
  "IF OR",
  "OR THEN IF",
  "OR THEN NOT",
  "OR NOT AND",
  "AND THEN OR",
  "NOT NOT OR",
  "IF OR AND",
  "THEN THEN OR",
  "IFF OR THEN",
  "IFF THEN OR",
  "AND AND OR",
  "NOT NOT IF",
  "NOT IF OR",
  "THEN AND OR",
  "AND IF OR",
  "AND THEN THEN",
  "IF AND OR OR",
  "AND AND AND",
  "OR IF THEN",
  "THEN THEN THEN",
  "OR IF OR",
  "AND NOT IF",
  "NOT THEN IF",
  "NOT AND OR",
  "THEN AND AND",
  "OR OR THEN",
  "AND THEN AND",
  "OR OR IF",
  "THEN OR OR",
  "IF THEN THEN",
  "IF OR OR",
  "AND OR OR OR",
  "NOT OR AND OR",
  "THEN AND AND OR.",
];

function randomSort(a: string, b: string): number {
  return Math.random() - 0.5;
}

function nextSentencePartMustBeAnAtom(sentenceParts: string[]): boolean {
  const [firstPart, ...sentencePartsRest] = sentenceParts;

  if (/^[A-Z]{1}$/.test(firstPart)) {
    if (sentencePartsRest.length === 0) {
      return true;
    }

    return nextSentencePartMustBeAConnector(sentencePartsRest);
  }

  if (firstPart === "NOT" || firstPart === "IF") {
    return nextSentencePartMustBeAnAtom(sentencePartsRest);
  }

  return false;
}

function nextSentencePartMustBeAConnector(sentenceParts: string[]): boolean {
  const [firstPart, ...sentenceParsRest] = sentenceParts;

  if (connectors.includes(firstPart)) {
    if (sentenceParsRest.length === 0) {
      return false;
    }

    return nextSentencePartMustBeAnAtom(sentenceParsRest);
  }

  return false;
}

function isPropositionalSentence(sentence: string): boolean {
  if (sentence) {
    const [firstPart, ...sentenceRest] = sentence.trim().split(" ");

    if (firstPart === "NOT" || firstPart === "IF") {
      return nextSentencePartMustBeAnAtom(sentenceRest);
    }

    if (/^[A-Z]{1}$/.test(firstPart)) {
      return nextSentencePartMustBeAConnector(sentenceRest);
    }

    return false;
  }

  return false;
}

function testPropositionalSentences(sentences: string[]) {
  return sentences.forEach((sentence) => {
    const result = isPropositionalSentence(sentence);

    if (result) {
      if (senteceExamples.includes(sentence)) {
        console.log(`Sentence: ${sentence} is OK ! TRUE POSITIVE !`);
        return true;
      }

      console.log(`Sentence: ${sentence} is OK ! FALSE POSITIVE !`);
      return true;
    }

    if (nonSentenceExamples.includes(sentence)) {
      console.log(`Sentence: ${sentence} is NOT OK ! TRUE NEGATIVE !`);
      return false;
    }

    console.log(`Sentence: ${sentence} is NOT OK ! FALSE NEGATIVE !`);
    return false;
  });
}

testPropositionalSentences(
  [...senteceExamples, ...nonSentenceExamples].sort(randomSort)
);
