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
        $.post("http://"+medzMateId+"/service.cfc?method=login&returnformat=json", {username:u,password:p}, function(res)
        {
           // return res;
        },"json");
    
        return (u == "Pedro" && p == "1234")
    }
    return false;
}