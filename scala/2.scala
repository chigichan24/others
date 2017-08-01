def getFirst(value: Option[String]):String = {
	if(value.isEmpty){
		return ""
	}
	if(value.get.length >= 1){
		return value.get.charAt(0)+""
	}
	else{
		return ""
	}
}