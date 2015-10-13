function validateLogin() {
    if (sendRequestToServer())
    {
        window.localStorage.setItem("currentUser", document.getElementById("username").value);
        return true; //User is loged in and current user saved
    }
    document.getElementById("password").value = '';
    return false; //username or passowrd incorrect
}

function sendRequestToServer()
{
    return (document.getElementById("username").value == "Pedro" && document.getElementById("password").value =="1234")
}