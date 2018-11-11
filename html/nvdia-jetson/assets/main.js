window.onload=function(){
document.getElementById("forward-left").onclick=function (){
    
};
document.getElementById("forward").onclick=function (){
    
};
document.getElementById("forward-right").onclick=function (){
    
};
document.getElementById("left").onclick=function (){
    
};
document.getElementById("stop").onclick=function (){
    
};
document.getElementById("right").onclick=function (){
    
};
document.getElementById("back-left").onclick=function (){
    
};
document.getElementById("back").onclick=function (){
    
};
document.getElementById("back-right").onclick=function (){

};


document.getElementById("but-one").onclick=function (){
    console.log("one");
    
};

document.getElementById("but-two").onclick=function (){
    console.log("three");
};

document.getElementById("but-three").onclick=function (){
    console.log("three"); 
};

document.onkeydown=function(event){
    var e = event || window.event || arguments.callee.caller.arguments[0];
    if(e && e.keyCode==37){
        console.log("left");
    }
    if(e && e.keyCode==38){
         console.log("up");
    }
    if(e && e.keyCode==39){
         console.log("right");
    }
    if(e && e.keyCode==40){
         console.log("down");
    }
    if(e && e.keyCode==32){
        console.log("stop");
    }
    }; 
}