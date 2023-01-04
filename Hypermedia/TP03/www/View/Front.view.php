<!DOCTYPE html>
<html lang="fr">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>TP03</title>
    
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/jstree/3.2.1/themes/default/style.min.css" />
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
  </head>
  <body>
    <div class="container">
      <div class="tree-container">
        <?php $this->includeComponent("ThirdExercise", $this->data); ?>
      </div>
      <div class="files-work-container">
        <div class="second-exercise-container">
          <?php $this->includeComponent("SecondExercise", $this->data); ?>
        </div>
        <div class="first-exercise-container">
          <?php $this->includeComponent("FirstExercise", $this->data); ?>
        </div>
      </div>
    </div>

    <style>
      * {
        margin: 0;
        padding: 0;
        outline: 0;
        box-sizing: border-box;
      }

      html, body {
        width: 100%;
        height: 100%;
      }

      .container {
        display: flex;
        flex-direction: row;
        flex-wrap: nowrap;
        align-content: center;
        justify-content: flex-start;
        align-items: center;

        width: 100%;
        height: 100%;
      }

      .tree-container {
        width: 30%;
        height: 100%;

        border: 1px solid black;
        overflow: auto;
      }

      .files-work-container {
        width: 70%;
        height: 100%;

        display: flex;
        flex-direction: column;
        flex-wrap: nowrap;
        align-content:  center;
        justify-content: flex-start;
        align-items: flex-start;
      }

      .second-exercise-container {
        border: 1px solid black;

        width: 100%;
        height: 25%;

        padding: 25px;
      }

      .first-exercise-container {
        border: 1px solid black;

        width: 100%;
        height: 75%;

        padding: 25px;
      }

      .first-exercise-container {
        margin-bottom: 25px;
      }
    </style>
  </body>
</html>
