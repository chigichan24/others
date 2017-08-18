def translate(num: Option[Int]): Option[String] = {
	val res = num.foreach{
		dictionary.get(_)
	}
	res
}