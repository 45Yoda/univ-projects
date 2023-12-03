#!/usr/bin/awk -f

BEGIN {
  # sort dos indices do tipo string de forma ascendente
  #PROCINFO["sorted_in"] = "@ind_str_asc"
  FS = ":";
}

{
  if(match($0, /^%dom(.*)$/,arx)){
    doms[arx[1]]
  }

  if(match($0, /^%THE(.*)$/, ary)) {
    type[ary[1]]

  }


  if(match($0,/^%inv(.*)$/,arz)){
    inv[arz[1]]
  }

}



END {

    #for(t in type)
        #if()


  for (dom in doms)
    print "Domain --> " dom

  for(t in type)
    print "Relation type --> " t

  for(i in inv)
    print "Inverse relation --> " i
}
