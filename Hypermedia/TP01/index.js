$(function() {
    $("#quick-links").on("click", "a", function(e) {
        var $tab = $("#quick-links"); // $("#" + e.currentTarget.href.split("#")[1]);
        $tab.toggleClass("active"); // .siblings().removeClass("active");
        sliderInit($('#slider'));
        return !1
    })
})
