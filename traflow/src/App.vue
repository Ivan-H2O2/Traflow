<template>
  <!-- <nav>
    <router-link to="/">Home</router-link>
  </nav> -->
  <div>
    <Header />
  </div>
  <router-view />
</template>

<script>
import Header from "@/components/Header";
export default {
  name: "LayOut",
  components: {
    Header,
  },
};
</script>
