function navigateToLoadingDeck() {
    window.location = "loadingDeckSelector.html";
}

function populate(frm, data) {
    //populate data from saved file
}

function initialize() {
    document.getElementById('Straw_id').value = window.localStorage.getItem("currentStraw");
    
    document.getElementById('form_1050292').addEventListener('submit', function (event) {
        event.preventDefault();
        var jobj = $(this).serializeArray();
        var test = JSON.stringify(jobj, null, 4);
        
        alert(test);
        navigateToLoadingDeck();
    });
}

