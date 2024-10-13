**exception**

<!-- try{
    // try someting
    if (/*there is an error/*)
        throw std::exception();
}
catch (std::exception & e){
    // Handle the error here
    e.what();
} -->

- we can specifiy the error with throw specifier;
with catch we can handle different types of a error;

- we can make general catch (with & e) or specific catch(name of the exception);

- l'exécution normale du programme s'arrête dès que l'exception est lancée, et le contrôle est passé à un gestionnaire d'exception.

- Il est parfaitement légal de lancer une exception dans un constructeur. En fait, c'est même la seule solution pour signaler une erreur lors de la construction d'un objet, puisque les constructeurs n'ont pas de valeur de retour;

- Lorsqu'une exception est lancée à partir d'un constructeur, la construction de l'objet échoue. Par conséquent, le compilateur n'appellera jamais le destructeur pour cet objet, puisque cela n'a pas de sens;