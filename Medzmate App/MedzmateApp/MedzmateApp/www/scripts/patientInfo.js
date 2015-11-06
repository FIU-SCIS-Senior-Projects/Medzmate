function saveDataToFile(ID, jsonData) {
    window.localStorage.setItem(ID, jsonData);
}

function sendToStation(ID, jsonData) {
    var medzMateId = window.localStorage.getItem("currentStation");
    var fName = ID + ".json"
    $.ajax({
        url: "http://" + medzMateId + ":3080/savePatient",
        // dataType: "jsonp"
        data: { fileName: fName, patientData: jsonData },
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

function onSubmitClick()
{
    var medzMateId = window.localStorage.getItem("currentStation");
    var patientInfoData = window.localStorage.getItem("temp");
    saveDataToFile(medzMateId + '-Patient', patientInfoData);
    sendToStation(medzMateId + '-Patient', patientInfoData);
    createLog(medzMateId + '-Patient', patientInfoData)
    console.log("submited popup");
}


function setconfrimationText(jobj) {
    $('#eldato').empty();
    $.each(jobj, function () {
        var s = this['name'].replace(/\_/g, ' ');
        $('#eldato').append('<p>' + s + ": " + this['value'] + '</p>');
    });
}

function createLog(ID, jobj) {
    var jsonOB = JSON.parse(jobj);
    var myDate = new Date();
    var strDate = (myDate.getMonth() + 1) + '/' + (myDate.getDate()) + '/' + myDate.getFullYear();
    var strTime = myDate.getHours() + ':' + myDate.getMinutes() + ':' + myDate.getSeconds();
    var test = " " + ID + "\r\nSchedule log";
    $.each(jsonOB, function () {
        var s = this['name'].replace(/\_/g, ' ');
        test = test + " \r\n" + s + ": " + this['value'];
    });

    writeTolog("MedzMate_" + ID + ".txt", test, navigateToMain); //needs to be replaced with medzmate id
}

function initialize() {
    //var strawID = window.localStorage.getItem("currentStraw");
    //document.getElementById('Straw_id').value = strawID;

    var thisForm = document.getElementById('patient-Info');

    thisForm.addEventListener('submit', function (event) {
        event.preventDefault();
        var jobj = $(this).serializeArray();
        var tempData = JSON.stringify(jobj);
        saveDataToFile("temp", tempData); // save the form to a temp location 
        setconfrimationText(jobj);
        $('#confirmDialog').popup("open");
        console.log("called popup");
    }
    );

   // populate(thisForm, strawID);

}