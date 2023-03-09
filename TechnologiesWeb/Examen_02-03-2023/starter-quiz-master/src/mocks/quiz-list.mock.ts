import { Quiz } from "../models/quiz.model";
import { Question } from "../models/question.model";

export const QUESTION_ACTOR: Question = {
  label: "Jean Gabin a joué dans...",
  answers: [
    {
      value: "Les tuches II",
      isCorrect: false,
    },
    {
      value: "La grande illusion",
      isCorrect: true,
    },
  ],
};

export const QUESTION_SPORT: Question = {
  label: "Le foot est un sport...",
  answers: [
    {
      value: "Collectif",
      isCorrect: true,
    },
    {
      value: "Individuel",
      isCorrect: false,
    },
  ],
};

export const QUIZ_LIST: Quiz[] = [
  {
    name: "Les Acteurs", // What's happening if I change this value..?
    theme: "Actor",
    questions: [QUESTION_ACTOR],
  },
  {
    name: "Les Sports",
    theme: "Sport",
    questions: [QUESTION_SPORT],
  },
];
