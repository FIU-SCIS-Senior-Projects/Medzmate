function navigateToLoadingDeck() {
    window.location = "loadingDeckSelector.html";
}

function initialize() {
    document.getElementById('form_1050292').addEventListener('submit', function (event) {
        event.preventDefault();
        var jobj = $(this).serializeArray();
      //  var test = " data: " + $(this).serialize();
      //  alert(test);
        alert(JSON.stringify(jobj, null, 4));
        navigateToLoadingDeck();
    });
}

