$(document).ready(function () {
  var results = [];
  var searchResultsList = $("#search-results");

  $("button#submit").click(function () {
    var query = $("input#query").val();

    if (query !== "") {
      $.ajax({
        type: "GET",
        url: `http://localhost:3000/search?query=${query}`,
        success: function (data) {
          results = data;
          searchResultsList.empty();
          if (results.length > 0) {
            results.forEach((result) => {
              var listItem = $("<li>");
              listItem.append(
                `<a href="${
                  result.document
                }" target="_blank"><h3>${result.document
                  .split(/[\\/]/)
                  .pop()}</h3></a>`
              );
              if (result.words && result.words.length > 0) {
                var wordsList = $("<ul>");
                result.words.forEach((word) => {
                  wordsList.append(
                    `<li>${word.word} (frequency: ${word.frequency})</li>`
                  );
                });
                listItem.append(wordsList);
              }
              searchResultsList.append(listItem);
            });
          } else {
            var listItem = $("<li>");
            listItem.append(`<h3>No documents found...</h3>`);
            searchResultsList.append(listItem);
          }
        },
        error: function (err) {
          alert(err.responseJSON.message);
        },
      });
    } else {
      alert("Please enter a query input");
    }
  });
});
