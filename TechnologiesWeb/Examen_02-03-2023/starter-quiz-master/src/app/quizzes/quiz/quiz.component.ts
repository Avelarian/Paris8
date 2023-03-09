import { Component, OnInit, Input, Output, EventEmitter } from "@angular/core";
import { Quiz } from "../../../models/quiz.model";

@Component({
  selector: "app-quiz",
  templateUrl: "./quiz.component.html",
  styleUrls: ["./quiz.component.scss"],
})
export class QuizComponent implements OnInit {
  @Input()
  quiz: Quiz;

  @Output()
  quizSelected: EventEmitter<boolean> = new EventEmitter<boolean>();

  @Output()
  quizDeleted: EventEmitter<Quiz> = new EventEmitter<Quiz>();

  constructor() {}

  ngOnInit() {}

  selectQuiz() {
    this.quizSelected.emit(true);
  }

  deleteQuiz(quiz: Quiz) {
    this.quizDeleted.emit(quiz);
  }

  quizThemeIcon() {
    switch (this.quiz.theme) {
      case "Actor":
        return "fa fa-book";
      case "Sport":
        return "fa fa-users";
      default:
        return "fa fa-question";
    }
  }
}
