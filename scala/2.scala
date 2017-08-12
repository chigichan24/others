def getFirst(value: Option[String]):String = {
	var top: String = ""
	value.foreach{ x=>
		top = x.take(1)
	}
	top
}