$(document).ready(function () {
  var token = "";

  $("button#Reset").click(function () {
    $("input#username").val("");
    $("input#password").val("");
  });

  $("button#Login").click(function () {
    var username = $("input#username").val();
    var password = $("input#password").val();

    if (username !== "" && password !== "") {
      $.ajax({
        type: "POST",
        url: "http://localhost:3000/auth/login",
        data: {
          username: username,
          password: password,
        },
        success: function (data) {
          token = data.access_token;
          alert(`User ${username} logged in successfully`);
        },
        error: function (err) {
          alert(err.responseJSON.message);
        },
      });
    } else {
      alert("Please enter username and password");
    }
  });

  $("button#Register").click(function () {
    var username = $("input#username").val();
    var password = $("input#password").val();

    if (username !== "" && password !== "") {
      $.ajax({
        type: "POST",
        url: "http://localhost:3000/auth/register",
        data: {
          username: username,
          password: password,
        },
        success: function (data) {
          alert(`User ${data.username} registered successfully`);
        },
        error: function (err) {
          alert(err.responseJSON.message);
        },
      });
    } else {
      alert("Please enter username and password");
    }
  });

  $("button#Test").click(function () {
    $.ajax({
      type: "GET",
      url: "http://localhost:3000/auth/profile",
      headers: {
        Authorization: `Bearer ${token}`,
      },
      success: function (data) {
        alert(`User ${data.username} is logged in`);
      },
      error: function (err) {
        alert(err.responseJSON.message);
      },
    });
  });
});
