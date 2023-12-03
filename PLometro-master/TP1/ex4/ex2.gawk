#!/usr/bin/awk -f

BEGIN {
  # sort dos indices
  # do tipo string de forma ascendente
  #  PROCINFO["sorted_in"] = "@ind_str_asc"
  FS = ":"
}

{
if(match($0, /^%THE.*$/)) {
    if(match($1,/<(.*)/,subst)){
        temp = $1
        $1 = subst[1]
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

        if(n == 1) print"(" $1 "," relat[i-1] "," $i ")"
        else{
            for(j=1; j<=n; j++)
                print"("$1 "," relat[i-1] "," inst[j] ")"
        }
    }


}

}

END {


}
