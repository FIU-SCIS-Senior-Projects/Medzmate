function sendToStation(saveName, jsonData, service) {
    var medzMateId = window.localStorage.getItem("currentStation");
    var fName = saveName + ".json";
    $.ajax({
        url: "http://" + medzMateId + ":3080/" + service,
        // dataType: "jsonp"
        data: { fileName: fName, strawSch: jsonData },
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