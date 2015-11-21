$(document).ready(function () {
    document.addEventListener("backbutton", onBackKeyDown, false);
    function onBackKeyDown(e) {
        console.log("backbutton pressed")
        e.preventDefault();
        navigateToLogin();
    }
    $(".ui-corner-all").hide();
    $(".ui-corner-all").toggle();
});