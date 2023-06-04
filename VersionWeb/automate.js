var pope = document.getElementById("pi");
var cd = document.getElementById("contentdiv");
var td = document.getElementById("titlediv");

document.getElementById("s").addEventListener("keydown", ({ key }) => {
  if (key === "Enter") {
    verifer();
  }
});

document.getElementById("close").addEventListener("click", () => {
  pope.classList.remove("pop-opened");
});
document.getElementById("backg").addEventListener("click", () => {
  pope.classList.remove("pop-opened");
});

function alterclass() {
  pope.classList.add("pop-opened");
}

function verifer() {
  var x = document.getElementById("s").value.split("");
  if (x === "") {
    td.innerHTML = "Succès";
    cd.innerHTML = "Le mot appartient au Langage";
    alterclass();
    return;
  } else {
    let l = x.length - 1;
    let state = 0;
    for (let i = 0; i <= l; i++) {
      if (x[i] == "a") {
        if (state == 2) {
          td.innerHTML = "Erreur";
          cd.innerHTML = "Le mot n'appartient pas au Langage";
          alterclass();
          return;
        } else if (state == 0) {
          state = 1;
        } else if (state == 1) {
          // pass
        }
      } else if (x[i] == "b") {
        if (state == 0) {
          // pass
        } else if (state == 1) {
          state = 2;
        } else if (state == 2) {
          state = 0;
        }
      } else {
        td.innerHTML = "Erreur";
        cd.innerHTML = "Le mot n'appartient pas au Langage";
        alterclass();
        return;
      }
    }
    td.innerHTML = "Succèes";
    cd.innerHTML = "Le mot appartient au Langage";
    alterclass();
  }
  document.getElementById("s").value = "";
}
