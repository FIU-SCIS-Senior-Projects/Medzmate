
//brings medcine inf screen on button click
function openDetails(btnId) {    
    var strawId = "";
    strawId = btnId;
    window.localStorage.setItem("currentStraw", strawId);
    console.log(window.localStorage.getItem("currentStraw"));
    window.location = "form.html";
}

document.addEventListener("backbutton", onBackKeyDown, false);
function onBackKeyDown(e) {
    console.log("backbutton pressed")
    e.preventDefault();
    navigateToMain();
}
