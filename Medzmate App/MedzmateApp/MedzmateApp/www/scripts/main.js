
document.addEventListener("backbutton", onBackKeyDown, false);
function onBackKeyDown(e) {
    console.log("backbutton pressed")
    e.preventDefault();
    navigateToLogin();
}
