def show(value: Option[String]):Unit = {
    if(value.isDefined){
    	println(value.get)
    }
}