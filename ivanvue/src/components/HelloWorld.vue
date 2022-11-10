<template>
  <div class="hello">
    <h1>{{ msg }}</h1>
    <p>
      For a guide and recipes on how to configure / customize this project,<br />
      check out the
      <a href="https://cli.vuejs.org" target="_blank" rel="noopener"
        >vue-cli documentation</a
      >.
    </p>
    <h3>Installed CLI Plugins</h3>
    <ul>
      <li>
        <a
          href="https://github.com/vuejs/vue-cli/tree/dev/packages/%40vue/cli-plugin-babel"
          target="_blank"
          rel="noopener"
          >babel</a
        >
      </li>
      <li>
        <a
          href="https://github.com/vuejs/vue-cli/tree/dev/packages/%40vue/cli-plugin-router"
          target="_blank"
          rel="noopener"
          >router</a
        >
      </li>
      <li>
        <a
          href="https://github.com/vuejs/vue-cli/tree/dev/packages/%40vue/cli-plugin-vuex"
          target="_blank"
          rel="noopener"
          >vuex</a
        >
      </li>
      <li>
        <a
          href="https://github.com/vuejs/vue-cli/tree/dev/packages/%40vue/cli-plugin-eslint"
          target="_blank"
          rel="noopener"
          >eslint</a
        >
      </li>
    </ul>
    <h3>Essential Links</h3>
    <ul>
      <li>
        <a href="https://vuejs.org" target="_blank" rel="noopener">Core Docs</a>
      </li>
      <li>
        <a href="https://forum.vuejs.org" target="_blank" rel="noopener"
          >Forum</a
        >
      </li>
      <li>
        <a href="https://chat.vuejs.org" target="_blank" rel="noopener"
          >Community Chat</a
        >
      </li>
      <li>
        <a href="https://twitter.com/vuejs" target="_blank" rel="noopener"
          >Twitter</a
        >
      </li>
      <li>
        <a href="https://news.vuejs.org" target="_blank" rel="noopener">News</a>
      </li>
    </ul>
    <h3>Ecosystem</h3>
    <ul>
      <li>
        <a href="https://router.vuejs.org" target="_blank" rel="noopener"
          >vue-router</a
        >
      </li>
      <li>
        <a href="https://vuex.vuejs.org" target="_blank" rel="noopener">vuex</a>
      </li>
      <li>
        <a
          href="https://github.com/vuejs/vue-devtools#vue-devtools"
          target="_blank"
          rel="noopener"
          >vue-devtools</a
        >
      </li>
      <li>
        <a href="https://vue-loader.vuejs.org" target="_blank" rel="noopener"
          >vue-loader</a
        >
      </li>
      <li>
        <a
          href="https://github.com/vuejs/awesome-vue"
          target="_blank"
          rel="noopener"
          >awesome-vue</a
        >
      </li>
    </ul>
  </div>
</template>

<script>
export default {
  name: "HelloWorld",
  props: {
    msg: String,
  },
};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<!-- <style scoped>
h3 {
  margin: 40px 0 0;
}
ul {
  list-style-type: none;
  padding: 0;
}
li {
  display: inline-block;
  margin: 0 10px;
}
a {
  color: #42b983;
}
</style> -->

<style scoped>
h3 {
  margin: 40px 0 0;
}
ul {
  list-style-type: none;
  padding: 0;
}
li {
  display: inline-block;
  margin: 0 10px;
}
a {
  color: #42b983;
}
body {
	font-family: source-sans-pro;
	background-color: #f2f2f2;
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
	margin-left: 0px;
	font-style: normal;
	font-weight: 200;
}
/* Container */
.container {
	width: 90%;
	margin-left: auto;
	margin-right: auto;
	height: 820px;
	background-color: #FFFFFF;
}
/* Navigation */
header {
	width: 100%;
	height: 5%;
	background-color: #52bad5;
	border-bottom: 1px solid #2C9AB7;
}
.logo {
	color: #fff;
	font-weight: bold;
	text-align: undefined;
	width: 10%;
	float: left;
	margin-top: 15px;
	margin-left: 25px;
	letter-spacing: 4px;
}
nav {
	float: right;
	width: 50%;
	text-align: right;
	margin-right: 25px;
}
header nav ul {
	list-style: none;
	float: right;
}
nav ul li {
	float: left;
	color: #55ff99;
	font-size: 14px;
	text-align: left;
	margin-right: 25px;
	letter-spacing: 2px;
	font-weight: bold;
	transition: all 0.3s linear;
}
ul li a {
	color: #2db8f8;
	text-decoration: none;
}
ul li:hover a {
	color: #0f80aa;
}
.hero_header {
	color: #e2e2e2;
	text-align: center;
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
	margin-left: 0px;
	letter-spacing: 4px;
}
/* Hero Section */
.hero {
	background-color: #D0D0D0;
	padding-top: 150px;
	padding-bottom: 150px;
	font-variant: normal;
}
h1 {
	color: #1d59f1d8;
}

.light {
	font-weight: bold;
	color: #CB2D2D;
	text-decoration: underline;
	background-color: #B3B3B3;
}
.tagline span a:hover {
}

.tagline {
	text-align: center;
	color: #FFFFFF;
	margin-top: 4px;
	font-weight: lighter;
	text-transform: uppercase;
	letter-spacing: 1px;
}
/* About Section */
.text_column {
	width: 29%;
	text-align: justify;
	font-weight: lighter;
	line-height: 25px;
	float: left;
	padding-left: 20px;
	padding-right: 20px;
	color: #A3A3A3;
}
.about {
	padding-left: 25px;
	padding-right: 25px;
	padding-top: 35px;
	display: inline-block;
	background-color: #FFFFFF;
	margin-top: 0px;
}
/* Stats Gallery */
.stats {
	color: #717070;
	margin-bottom: 5px;
}
.gallery {
	clear: both;
	display: inline-block;
	width: 100%;
	background-color: #FFFFFF;
	/* [disabled]min-width: 400px;
*/
	padding-bottom: 35px;
	padding-top: 0px;
	margin-top: -5px;
	margin-bottom: 0px;
}
.thumbnail {
	width: 25%;
	text-align: center;
	float: left;
	margin-top: 35px;
}
.gallery .thumbnail h4 {
	margin-top: 5px;
	margin-right: 5px;
	margin-bottom: 5px;
	margin-left: 5px;
	color: #52BAD5;
}
.gallery .thumbnail p {
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
	margin-left: 0px;
	color: #A3A3A3;
}
/* Parallax Section */
.banner {
	background-color: #E3F3F7;
	/* background-image: url(../images/parallax.png); */
	height: 400px;
	background-attachment: fixed;
	background-size: cover;
	background-repeat: no-repeat;
}
.parallax {
	color: #FFFFFF;
	text-align: right;
	padding-right: 100px;
	padding-top: 110px;
	letter-spacing: 2px;
	margin-top: 0px;
	padding-left: 0px;
}
.parallax_description {
	color: #FFFFFF;
	text-align: right;
	padding-right: 100px;
	width: 30%;
	float: right;
	font-weight: lighter;
	line-height: 23px;
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
	margin-left: 0px;
}
/* More info */
footer {
	background-color: #FFFFFF;
	padding-bottom: 35px;
}
.footer_column {
	width: 50%;
	text-align: center;
	padding-top: 30px;
	float: left;
}
footer .footer_column h3 {
	color: #B3B3B3;
	text-align: center;
}
footer .footer_column p {
	color: #717070;
	background-color: #FFFFFF;
}
.cards {
	width: 100%;
	height: auto;
	max-width: 400px;
	max-height: 200px;
}
footer .footer_column p {
	padding-left: 30px;
	padding-right: 30px;
	text-align: justify;
	line-height: 25px;
	font-weight: lighter;
	margin-left: 20px;
	margin-right: 20px;
}
.button {
	width: 200px;
	margin-top: 40px;
	margin-right: auto;
	margin-bottom: auto;
	margin-left: auto;
	padding-top: 20px;
	padding-right: 10px;
	padding-bottom: 20px;
	padding-left: 10px;
	text-align: center;
	vertical-align: middle;
	border-radius: 0px;
	text-transform: uppercase;
	font-weight: bold;
	letter-spacing: 2px;
	border: 3px solid #FFFFFF;
	color: #FFFFFF;
	transition: all 0.3s linear;
}
.button:hover {
	background-color: #FEFEFE;
	color: #C4C4C4;
	cursor: pointer;
}
.copyright {
	text-align: center;
	padding-top: 20px;
	padding-bottom: 20px;
	background-color: #717070;
	color: #FFFFFF;
	text-transform: uppercase;
	font-weight: lighter;
	letter-spacing: 2px;
	border-top-width: 2px;
}
.footer_banner {
	background-color: #B3B3B3;
	padding-top: 60px;
	padding-bottom: 60PX;
	margin-bottom: 0px;
	/* background-image: url(../images/pattern.png);*/
	background-repeat: repeat;
}
footer {
	display: inline-block;
}
.hidden {
	display: none;
}
#title1   {
	font-family: "华文新魏";
	font-variant: normal;
	font-weight: normal;
	position: relative;
	font-size: 50px;
}
#one {
	font-family: Constantia, "Lucida Bright", "DejaVu Serif", Georgia, serif;
}



/* Mobile */
@media (max-width: 320px) {
.logo {
	width: 100%;
	text-align: center;
	margin-top: 13px;
	margin-right: 0px;
	margin-bottom: 0px;
	margin-left: 0px;
}
.container header nav {
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
	margin-left: 0px;
	width: 100%;
	float: none;
	display: none;
}
header nav ul {
}
nav ul li {
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
	margin-left: 0px;
	width: 100%;
	text-align: center;
}
.text_column {
	width: 100%;
	text-align: justify;
	padding-top: 0px;
	padding-right: 0px;
	padding-bottom: 0px;
	padding-left: 0px;
}
.thumbnail {
	width: 100%;
}
.footer_column {
	width: 100%;
	margin-top: 0px;
}
.parallax {
	text-align: center;
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
	margin-left: 0px;
	padding-top: 40%;
	padding-right: 0px;
	padding-bottom: 0px;
	padding-left: 0px;
	width: 100%;
	font-size: 18px;
}
.parallax_description {
	padding-top: 0px;
	padding-right: 0px;
	padding-bottom: 0px;
	padding-left: 0px;
	width: 90%;
	margin-top: 25px;
	margin-right: 0px;
	margin-bottom: 0px;
	margin-left: 12px;
	float: none;
	text-align: center;
}
.banner {
	background-color: #2D9AB7;
	background-image: none;
}
.tagline {
	margin-top: 20px;
	line-height: 22px;
}
.hero_header {
	padding-left: 10px;
	padding-right: 10px;
	line-height: 22px;
	text-align: center;
}
}

/* Small Tablets */
@media (min-width: 321px)and (max-width: 767px) {
.logo {
	width: 100%;
	text-align: center;
	margin-top: 13px;
	margin-right: 0px;
	margin-bottom: 0px;
	margin-left: 0px;
	color: #043745;
}
.container header nav {
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
	margin-left: 0px;
	width: 100%;
	float: none;
	overflow: auto;
	display: inline-block;
	background: #52bad5;
}
header nav ul {
	padding: 0px;
	float: none;
}
nav ul li {
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
	margin-left: 0px;
	width: 100%;
	text-align: center;
	padding-top: 8px;
	padding-bottom: 8px;
}
.text_column {
	width: 100%;
	text-align: left;
	padding-top: 0px;
	padding-right: 0px;
	padding-bottom: 0px;
	padding-left: 0px;
}
.thumbnail {
	width: 100%;
}
.footer_column {
	width: 100%;
	margin-top: 0px;
}
.parallax {
	text-align: center;
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
	margin-left: 0px;
	padding-top: 40%;
	padding-right: 0px;
	padding-bottom: 0px;
	padding-left: 0px;
	width: 100%;
	font-size: 18px;
}
.parallax_description {
	padding-top: 0px;
	padding-right: 0px;
	padding-bottom: 0px;
	padding-left: 0px;
	margin-top: 30%;
	margin-right: 0px;
	margin-bottom: 0px;
	margin-left: 0px;
	float: none;
	width: 100%;
	text-align: center;
}
.thumbnail {
	width: 50%;
}
.parallax {
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
	margin-left: 0px;
	padding-right: 0px;
	padding-bottom: 0px;
	padding-left: 0px;
	padding-top: 20%;
}
.parallax_description {
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
	margin-left: 0px;
	width: 100%;
	padding-top: 30px;
}
.banner {
	padding-left: 20px;
	padding-right: 20px;
}
.footer_column {
	width: 100%;
}
}

/* Small Desktops */
@media (min-width: 768px) and (max-width: 1096px) {
.text_column {
	width: 100%;
}
.thumbnail {
	width: 50%;
}
.text_column {
	width: 100%;
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
	margin-left: 0px;
	padding-top: 0px;
	padding-right: 0px;
	padding-bottom: 0px;
	padding-left: 0px;
}
.banner {
	margin-top: 0px;
	padding-top: 0px;
}
}

</style>
