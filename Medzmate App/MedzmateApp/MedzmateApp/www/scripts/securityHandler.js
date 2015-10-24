function validateLogin() {
    var medzMateId = document.getElementById("station").value;
    if (sendRequestToServer(medzMateId))
    {
        window.localStorage.setItem("currentUser", document.getElementById("username").value);
        window.localStorage.setItem("currentStation", medzMateId);
        return true; //User is loged in and current user saved
    }
    document.getElementById("password").value = '';
    return false; //username or passowrd incorrect
}

function sendRequestToServer(medzMateId)
{
    var u = document.getElementById("username").value;
    var p = document.getElementById("password").value;
    
    if (u != '' && p != '')
    {
        //console.log("posting" + "http://" + medzMateId + ":3080");
        //$.post("http://" + medzMateId + ":3080", { username: u, password: p }, function (res) ///service.cfc?method=login&returnformat=json
        //{
        //    // return res;
        //    console.log("hiso algo fileEntry.name ",res);
        //});
        var isValid = 1;
        $.ajax({
            url: "http://" + medzMateId + ":3080/login",
            // dataType: "jsonp"
            data: { username: u, password: p },
            type: 'POST',
            jsonpCallback: 'callback', // this is not relevant to the POST anymore
            success: function (data) {
                console.log('Success: ', data);
                if (data=="OK loged") {
                    isValid = 0;
                    console.log("isValid seccess", isValid);
                }
            },
            error: function (xhr, status, error) {
                console.log('Error: ' + error.message);
            },
            async: false
        });
        
    }

    console.log("isValid ", isValid);
    return isValid <1;
}