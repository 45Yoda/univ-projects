#!/usr/bin/awk -f


BEGIN {
  # sort dos indices
  # do tipo string de forma ascendente
  #  PROCINFO["sorted_in"] = "@ind_str_asc"
  FS = ":"
  counter = 0
}


{

if(match($0, /^%THE.*$/)) {
    #apanha tudo depois de <
    if(match($1,/<(.*)/,subst)){
        temp = $1
        $1 = subst[1]
        iof = $1
        #para os prints n é necessário o primeiro termo
        $1 = ""
        rel = $0
        $1 = temp
    }
    else{
        $1 = ""
        rel = $0
    }
}

if(match($1,/^[A-Za-z]/)){

    split(rel, relat, " ")

    for(r=1; r<=NF;r++){
        sub(/<[A-Za-z].+/," ", relat[r])
    }

    for(i=2;i<=NF;i++){

        n = split($i, inst, "|");

        if(n == 1){
            printable[counter] = $1","relat[i-1]","$i
            counter++;

        }
        else{
            for(j=1; j<=n; j++){
                printable[counter] = $1","relat[i-1]","inst[j]
<<<<<<< HEAD:ex4/ex3.gawk
                counter++;
            }
=======
                #printable[counter][c] = relat[i-1]","inst[j]
                counter++;
            }

>>>>>>> a9f7368f42c85b6069945f213f019970ce16ba0f:TP1/ex4/ex3.gawk
        }
    }
}

}


END {
<<<<<<< HEAD:ex4/ex3.gawk

=======
>>>>>>> a9f7368f42c85b6069945f213f019970ce16ba0f:TP1/ex4/ex3.gawk
    s=""
    for(x=0;x<counter;x++){

        y=split(printable[x],t,",")

        if(s!=t[1]){
            s = t[1]
            printf("\n")
            print(s)
            if(iof!="") print "iof: " iof
        }

        #relacionamento + instancia
        for(z=2;z<=y;z++){
            if(z==2){
                printf t[z]" : "
            }
            else{
                printf t[z]" "
            }
        }
        printf("\n")


    }
}
