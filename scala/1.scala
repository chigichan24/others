def show(value: Option[String]):Unit = {
	for (
		v <- value
	){
		println(v)
	}
}