def translate(num: Option[Int]): Option[String] = {
	dictionary.get(num.get)
}