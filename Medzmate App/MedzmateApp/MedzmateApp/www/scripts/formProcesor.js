function navigateToLoadingDeck() {
    window.location = "loadingDeckSelector.html";
}
function proccessForm() {
    var medicine = document.getElementById("Medicine_Name").value;
    var str = '';
    var elem = document.getElementById('form_1050292').elements;
    for (var i = 0; i < elem.length; i++)
    {
        str += "\n" + elem[i].id + " ";
        str += elem[i].value + " ";
        str += "...";
    }

    alert("medicine " + medicine + " elemts " + str);

}