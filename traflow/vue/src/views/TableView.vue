// 该文件用于理解前后端的交互
<template>
  <!-- 表格表头 -->
  <div style="padding: 10px">
    <!-- 功能区域 -->
    <div style="margin: 10px 0">
      <el-button type="primary">新增</el-button>
      <el-button type="primary">导入</el-button>
      <el-button type="primary">导出</el-button>
    </div>
    <!-- 搜索区域 -->
    <div style="margin: 10px 0">
      <el-input
        v-model="search"
        placeholder="Please input"
        style="width: 20%"
      />
      <el-button type="primary" plain style="margin: 5px">查询</el-button>
    </div>
    <!-- border: 边框  stripe: 斑马纹 -->
    <el-table :data="tableData" border stripe style="width: 100%">
      <el-table-column prop="date" label="Date" width="180" sortable />
      <el-table-column prop="name" label="Name" width="180" sortable />
      <el-table-column prop="address" label="Address" sortable />
      <el-table-column fixed="right" label="Operations" width="120">
        <template #default>
          <el-button link type="primary" @click="handleEdit">Edit</el-button>
          <!-- 反馈组件 -->
          <el-popconfirm title="Are you sure to delete this?">
            <template #reference>
              <el-button type="text">Delete</el-button>
            </template>
          </el-popconfirm>
        </template>
      </el-table-column>
    </el-table>
    <div class="demo-pagination-block" style="margin: 10px 0">
      <div class="demonstration">All combined</div>
      <el-pagination
        v-model:current-page="currentPage4"
        v-model:page-size="pageSize4"
        :page-sizes="[5, 10, 15, 20]"
        :small="small"
        :disabled="disabled"
        :background="background"
        layout="total, sizes, prev, pager, next, jumper"
        :total="20"
        @size-change="handleSizeChange"
        @current-change="handleCurrentChange"
      />
    </div>
  </div>
</template>

<script scope setup>
// 表格数据
const tableData = [
  {
    date: "2016-05-03",
    name: "Tom",
    address: "No. 189, Grove St, Los Angeles",
  },
  {
    date: "2016-05-02",
    name: "Tom",
    address: "No. 189, Grove St, Los Angeles",
  },
  {
    date: "2016-05-04",
    name: "Tom",
    address: "No. 189, Grove St, Los Angeles",
  },
  {
    date: "2016-05-01",
    name: "Tom",
    address: "No. 189, Grove St, Los Angeles",
  },
];
import { ref } from "vue";

// const currentPage1 = ref(5);
// const currentPage2 = ref(5);
// const currentPage3 = ref(5);
const currentPage4 = ref(4);
// const pageSize2 = ref(100);
// const pageSize3 = ref(100);
const pageSize4 = ref(20);
const small = ref(false);
const background = ref(false);
const disabled = ref(false);

// const handleSizeChange = (val: number) => {
//   console.log(`${val} items per page`);
// };
// const handleCurrentChange = (val: number) => {
//   console.log(`current page: ${val}`);
// };
function handleEdit() {}
</script>
