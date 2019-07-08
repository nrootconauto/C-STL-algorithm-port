var type=/(\w|_)+\*?\s*/
var name=/\w+/
function toMacro(str) {
  let name1=String(str.match(name));
  str=str.replace(name,"")
  str=str.replace(/\((.+)\)/,"$1")
  args=str.split(",");
  let argNames=[]
  let types=[];
  for(let arg of args) {
	  types.push(String(arg.match(type)[0]))
	  arg=String(arg.replace(type,""))
	  argNames.push(String(arg.match(name)))
  }
  argNames[0]=`sizeof(type)`
  let originalNames=argNames.slice(1)
  for(let an in argNames.slice(1)) {
	  an=Number(an)+1;
	  let anInst=argNames[an]
	  
	  if(types[an].indexOf("algo_predicate")==0) {
		  argNames[an]=`$AP(${anInst})`;
		  continue;
	  }
	  if(types[an].indexOf("algo_")==0) {
		  argNames[an]=`$AF(${anInst})`
		  continue
	  } else
		argNames[an]=`$AA(${anInst})`
  }
  return `#define ${name1}(type,${originalNames.join(',')})`+("__"+name1+"("+argNames.join(",")+")")
}

console.log(toMacro("aglo_sorted_includes(size_t size,char* first1,char* last1,char* first2,char* last2,algo_predicate pred)"));
debugger;
