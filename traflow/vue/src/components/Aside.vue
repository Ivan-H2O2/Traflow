<template>
  <div class="name">
    <el-row class="tac">
      <el-col :span="12">
        <el-menu
          style="width: 200px; min-height: calc(100vh - 50px)"
          active-text-color="#0022ee"
          background-color="#fff"
          class="el-menu-vertical-demo"
          default-active="1"
          text-color="#000"
          @open="handleOpen"
          @close="handleClose"
        >
          <router-link class="list-group-item" active-class="active" to="/home">
            <el-menu-item index="1">
              <el-icon><icon-menu /></el-icon>
              <span> 主页</span>
            </el-menu-item>
          </router-link>
          <!-- 禁用disabled的话可以这样写 -->
          <!-- <el-menu-item index="3"> disabled     -->
          <router-link
            class="list-group-item"
            active-class="active"
            to="/table"
          >
            <el-menu-item index="2">
              <el-icon><icon-menu /></el-icon>
              <span> 测试表格</span>
            </el-menu-item>
          </router-link>
          <el-sub-menu index="3">
            <template #title>
              <el-icon><location /></el-icon>
              <span>选择仿真模型</span>
            </template>
            <el-menu-item-group title="跟车模型">
              <el-menu-item index="3-1">仿真1</el-menu-item>
              <el-menu-item index="3-2">仿真2</el-menu-item>
            </el-menu-item-group>
          </el-sub-menu>
        </el-menu>
      </el-col>
    </el-row>
  </div>
</template>

<script>
export default {
  name: "MyAside",
};
</script>

<style scoped>
.list-group-item {
  /* 去掉下划线 */
  text-decoration-line: none;
}
</style>
