﻿function saveDataToFile(ID, jsonData) {
    window.localStorage.setItem(ID, jsonData);
}

function onSubmitClick() {
    var medzMateId = window.localStorage.getItem("currentStation");
    var patientInfoData = window.localStorage.getItem("temp");
    saveDataToFile(medzMateId + '-Settings', patientInfoData);
   // sendToStation(medzMateId + '-Patient', patientInfoData);
    createLog(medzMateId + '-Settings', patientInfoData)
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

    var thisForm = document.getElementById('Medzmate-Settings');

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
}