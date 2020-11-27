var myObj = [{nom: “Fanny”, moisAnniversaire: 09, jourAnniversaire:18},
             {nom: “Manon”, moisAnniversaire: 11, jourAnniversaire:13},
             {nom: “Francelin”, moisAnniversaire: 7, jourAnniversaire:30},
             {nom: “Noëmie”, moisAnniversaire: 6, jourAnniversaire:21},
             {nom: “Margaux”, moisAnniversaire: 2, jourAnniversaire:5},
             {nom: “Joanna”, moisAnniversaire: 12, jourAnniversaire:18}]
var d = new Date();
var moisAuj = d.getMonth() + 1 ;
var dateAuj = d.getDate()
//console.log(d.toString());
//console.log(dateAuj.toString());
var i;
let anniversaire = “”;
let counter = 0;
    for (i = 0; i < myObj.length; i++) {
 if (((d.getMonth()+1)>myObj[i].moisAnniversaire) ||
   (((d.getMonth()+1) === myObj[i].moisAnniversaire) && (dateAuj > myObj[i].jourAnniversaire)))
                                                                       {
   anniversaire = new Date(d.getFullYear()+1, myObj[i].moisAnniversaire -1, myObj[i].jourAnniversaire)
     //console.log(“b anniversaire=“+anniversaire)
  } else {
     anniversaire = new Date(d.getFullYear(), myObj[i].moisAnniversaire -1, myObj[i].jourAnniversaire)
     //console.log(“anniversaire=“+anniversaire)
  }
  //console.log(anniversaire.toString());
   // différence des heures
  var time_diff = anniversaire.getTime() - d.getTime();
          // différence de jours
  var days_Diff = time_diff / (1000 * 3600 * 24);
         // afficher la différence
 if (days_Diff < 15){
   console.log(“C’est l’anniversaire de ” + myObj[i].nom + ” le ” + myObj[i].jourAnniversaire);
   counter += 1;
 }
}
if(counter === 0){
   console.log(“Il n’y a pas d’anniversaire à venir dans les 15 jours”);
 }
