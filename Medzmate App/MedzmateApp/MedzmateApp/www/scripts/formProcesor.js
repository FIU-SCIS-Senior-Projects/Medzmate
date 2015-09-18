function navigateToLoadingDeck() {
    window.location = "loadingDeckSelector.html";
}
function proccessForm(e) {
    var medicine = document.getElementById("element_1").value;
    var str = '';
    var elem = document.getElementById('form_1050292').elements;
    for (var i = 0; i < elem.length; i++) {
        str += "\n" + elem[i].name + " ";
        str += elem[i].value + " ";
        str += "...";
    }

    alert("medicine " + medicine + " elemts " + str);

}