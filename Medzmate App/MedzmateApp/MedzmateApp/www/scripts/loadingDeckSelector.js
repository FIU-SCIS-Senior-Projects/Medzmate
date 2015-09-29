
var strawId = "";
//brings medcine inf screen on button click
function openDetails(btnId) {
    strawId = btnId;
    window.localStorage.setItem("currentStraw", strawId);
    console.log(window.localStorage.getItem("currentStraw"));
    window.location = "form.html";
}
