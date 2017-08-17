def translate(num: Option[Int]): Option[String] = {
	num match {
		case Some(x) => dictionary.get(x)
		case _ => None
	}
}