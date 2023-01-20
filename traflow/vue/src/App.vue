<template>
  <!-- <nav>
    <router-link to="/">Home</router-link>
  </nav> -->
  <div>
    <!-- 主体 -->
    <Header />
    <div style="display: flex">
      <!-- 侧边栏 -->
      <Aside />
      <!-- 内容区域 -->
      <router-view />
    </div>
  </div>
</template>

<script>
import Header from "@/components/Header";
import Aside from "@/components/Aside";
export default {
  name: "LayOut",
  components: {
    Header,
    Aside,
  },
};
</script>
