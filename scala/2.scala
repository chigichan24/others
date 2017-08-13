def getFirst(value: Option[String]):String = {
	value.fold(""){_.take(1)}
}