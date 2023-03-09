var __spreadArray = (this && this.__spreadArray) || function (to, from, pack) {
    if (pack || arguments.length === 2) for (var i = 0, l = from.length, ar; i < l; i++) {
        if (ar || !(i in from)) {
            if (!ar) ar = Array.prototype.slice.call(from, 0, i);
            ar[i] = from[i];
        }
    }
    return to.concat(ar || Array.prototype.slice.call(from));
};
var connectors = ["AND", "OR", "NOT", "IF", "THEN", "IFF"];
var senteceExamples = [
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
    "P IF AND ONLY IF Q",
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
var nonSentenceExamples = [
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
function randomSort(a, b) {
    return Math.random() - 0.5;
}
function nextSentencePartMustBeAnAtom(sentenceParts) {
    var firstPart = sentenceParts[0], sentencePartsRest = sentenceParts.slice(1);
    if (/[A-Z]/.test(firstPart)) {
        if (sentencePartsRest.length === 0) {
            return true;
        }
        return nextSentencePartMustBeAConnector(sentencePartsRest);
    }
    return false;
}
function nextSentencePartMustBeAConnector(sentenceParts) {
    var firstPart = sentenceParts[0], sentenceParsRest = sentenceParts.slice(1);
    console.log(connectors);
    if (connectors.includes(firstPart)) {
        if (sentenceParsRest.length === 0) {
            return false;
        }
        return nextSentencePartMustBeAnAtom(sentenceParsRest);
    }
    return false;
}
function isPropositionalSentence(sentence) {
    if (sentence) {
        var _a = sentence.trim().split(" "), firstPart = _a[0], sentenceRest = _a.slice(1);
        if (firstPart === "NOT" || firstPart === "IF") {
            return nextSentencePartMustBeAnAtom(sentenceRest);
        }
        if (/[A-Z]/.test(firstPart)) {
            return nextSentencePartMustBeAConnector(sentenceRest);
        }
        return false;
    }
    return false;
}
function testPropositionalSentences(sentences) {
    return sentences.every(function (sentence) {
        var result = isPropositionalSentence(sentence);
        if (result) {
            console.log("Sentence: ".concat(sentence, " is OK !"));
            return true;
        }
        console.log("Sentence: ".concat(sentence, " is NOT OK !"));
        return false;
    });
}
testPropositionalSentences(__spreadArray(__spreadArray([], senteceExamples, true), nonSentenceExamples, true).sort(randomSort));
