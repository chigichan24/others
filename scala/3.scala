def translate(num: Option[Int]): Option[String] = {
	num.flatMap{dictionary.get}
}