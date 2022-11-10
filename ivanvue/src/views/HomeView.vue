<template>
  <div class="home">
    <!-- <img alt="Vue logo" src="../assets/logo.png" /> -->
    <img id="fduPic" alt="FDU logo" src="./images/fdu.jpg" />
    <HelloWorld msg="Welcome to Your TraFlowSim" />
  </div>
</template>

<script>
// @ is an alias to /src
import HelloWorld from "@/components/HelloWorld.vue";

export default {
  name: "HomeView",
  components: {
    HelloWorld,
  },
};
</script>

<style>
#fduPic {
  width: 220px;
}
</style>
