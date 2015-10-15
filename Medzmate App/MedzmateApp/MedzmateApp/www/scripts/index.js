// For an introduction to the Blank template, see the following documentation:
// http://go.microsoft.com/fwlink/?LinkID=397704
// To debug code on page load in Ripple or on Android devices/emulators: launch your app, set breakpoints, 
// and then run "window.location.reload()" in the JavaScript Console.
(function () {
    "use strict";

    document.addEventListener( 'deviceready', onDeviceReady.bind( this ), false );

    function onDeviceReady() {
        // Handle the Cordova pause and resume events
        document.addEventListener('pause', onPause.bind(this), false);
        document.addEventListener('resume', onResume.bind(this), false);
        
        // TODO: Cordova has been loaded. Perform any initialization that requires Cordova here.
        document.getElementById("btnLogin").onclick = function () {
            $("#btnLogin", this).attr("disabled", "disabled");
            var medzMateId = document.getElementById("station").value;
            if (medzMateId !="")
                if (validateLogin()) {
                    writeTolog("MedzMate_General_log"+".txt", "User Loged in", function callback(test) { window.location = "loadingDeckSelector.html"; })
                }
                else {
                    alert("Invalid Username and/or Password \n Please try again");
                    $("#btnLogin").removeAttr("disabled");
                }
            else {
                alert("Medzmate Id cannot be blank. Please try again");
                $("#btnLogin").removeAttr("disabled");
            }

            
        }
    };

    document.addEventListener("backbutton", onBackKeyDown, false);
    function onBackKeyDown(e) {
        console.log("backbutton pressed")
        e.preventDefault();
    }

    function onPause() {
        // TODO: This application has been suspended. Save application state here.
    };

    function onResume() {
        // TODO: This application has been reactivated. Restore application state here.
    };
} )();