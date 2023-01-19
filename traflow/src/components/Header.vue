// Header组件
<template>
  <div class="container">
    <!-- 标题 -->
    <div class="name">交通流平台</div>
    <div style="flex: 1"></div>
    <div class="image">
      <!-- 复旦LOGO -->
      <img
        src="../assets/images/fduLOGO.jpg"
        alt="LOGO"
        style="width: 50px; height: 50px"
      />
    </div>
    <div class="dropdown-menu">
      <div class="items-center">
        <el-dropdown split-button type="primary" @click="handleClick">
          <!-- 想插入一个icon -->
          <el-icon><User /></el-icon>
          Ivan-H2O2
          <template #dropdown>
            <el-dropdown-menu>
              <!-- 个人信息和退出系统 -->
              <el-dropdown-item>个人信息</el-dropdown-item>
              <el-dropdown-item>退出系统</el-dropdown-item>
            </el-dropdown-menu>
          </template>
        </el-dropdown>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: "MyHeader",
};
</script>

<style scoped>
/* 设置容器样式 */
.container {
  height: 50px;
  line-height: 50px;
  color: blue;
  border-bottom: 1px solid #ccc;
  display: flex;
}

/* 设置容器中name的样式 */
.name {
  width: 200px;
  padding-left: 30px;
  font-weight: bold;
  color: blue;
}

.dropdown-menu {
  width: 150px;
  padding-top: 17px;
}

/* 设置el-dropdown之间的间距 */
.example-showcase .el-dropdown + .el-dropdown {
  margin-left: 15px;
}

/* 设置el-dropdown-link的样式 */
.example-showcase .el-dropdown-link {
  cursor: pointer;
  color: var(--el-color-primary);
  display: flex;
  align-items: center;
}
</style>
