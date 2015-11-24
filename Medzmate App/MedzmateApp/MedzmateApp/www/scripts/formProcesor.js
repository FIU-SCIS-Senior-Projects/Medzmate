function populate(frm, id) {
    //populate data from saved file
    var jobj = window.localStorage.getItem(id);
    if (jobj != null) {
        var jsonOB = JSON.parse(jobj);
        var test = JSON.stringify(jsonOB, null, 4);

        $.each(jsonOB, function () {
            $('input[name =' + this['name'] + ']').val(this['value']);
            $('textarea[name =' + this['name'] + ']').val(this['value']); //set symptoms and effects
            $('input[name =' + this['name'] + ']').attr("checked", true); //set frequency values and link with other containers
            if (this['name'] == 'Number_of_Doses') {
                $("#" + this['name']).val(this['value']);
            }

        });

    }

}

function createLog(strawId, jobj) {
    var jsonOB = JSON.parse(jobj);
    var myDate = new Date();
    var strDate = (myDate.getMonth() + 1) + '/' + (myDate.getDate()) + '/' + myDate.getFullYear();
    var strTime = myDate.getHours() + ':' + myDate.getMinutes() + ':' + myDate.getSeconds();
    var test = "StrawId " + strawId + "\r\nSchedule log";
    $.each(jsonOB, function () {
        var s = this['name'].replace(/\_/g, ' ');
        test = test + " \r\n" + s + ": " + this['value'];
    });

    writeTolog("MedzMate_" + strawId + ".txt", test, navigateToLoadingDeck); //needs to be replaced with medzmate id
}

function saveDataToFile(strawID, jsonData) {
    window.localStorage.setItem(strawID, jsonData);
}

function onSubmitClick() {
    var strawID = document.getElementById('Straw_id').value;
    var schedule = window.localStorage.getItem("temp");
    saveDataToFile(strawID, schedule);
    sendToStation(strawID, schedule);
    createLog(strawID, schedule)
    // navigateToLoadingDeck();
}

function sendToStation(strawId, schedule) {
    var medzMateId = window.localStorage.getItem("currentStation");
    var fName = "Straw_" + strawId + ".json"
    $.ajax({
        url: "http://" + medzMateId + ":3080/saveStraw",
        // dataType: "jsonp"
        data: { fileName: fName, strawSch: schedule },
        // fileName: 'TestStraw123456',
        type: 'POST',
        jsonpCallback: 'callback', // this is not relevant to the POST anymore
        success: function (data) {
            console.log('Success: ', data);
            if (data == "OK loged") {
                isValid = 0;
                console.log("isValid seccess", isValid);
            }
        },
        error: function (xhr, status, error) {
            console.log('Error: ' + error.message);
        },
        //async: false
    });
}


function setconfrimationText(jobj) {
    $('#eldato').empty();
    $.each(jobj, function () {
        var s = this['name'].replace(/\_/g, ' ');
        $('#eldato').append('<p>' + s + ": " + this['value'] + '</p>');
    });
}

document.addEventListener("backbutton", onBackKeyDown, false);
function onBackKeyDown(e) {
    console.log("backbutton pressed")
    e.preventDefault();
    document.getElementById('cancelBtn').click();
}

function initialize() {
    var strawID = window.localStorage.getItem("currentStraw");
    document.getElementById('Straw_id').value = strawID;

    var thisForm = document.getElementById('form_1050292');

    thisForm.addEventListener('submit', function (event) {
        event.preventDefault();
        var jobj = $(this).serializeArray();
        var tempSchedule = JSON.stringify(jobj);
        saveDataToFile("temp", tempSchedule); // save the form to a temp location 
        setconfrimationText(jobj);
        $('#confirmDialog').popup("open");
        console.log("called popup");
    }
    ); 

    populate(thisForm, strawID);

}
