def translate(num: Option[Int]): Option[String] = {
	for(
		s <- num
	) yield dictionary.get(s).get
}