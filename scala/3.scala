def translate(num: Option[Int]): Option[String] = {
	if(num.isEmpty){
		return None
	}
	val r = dictionary.get(num.get)
	r
}