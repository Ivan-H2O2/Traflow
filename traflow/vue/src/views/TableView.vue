// 该文件通过表格理解前后端的交互
<template>
  <!-- 表格表头 -->
  <div style="padding: 10px">
    <!-- 功能区域 -->
    <div style="margin: 10px 0">
      <el-button type="primary" @click="add">新增</el-button>
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
    <!-- label的规则：首字母大写  | 属性的规则：全部小写   驼峰？-->
    <el-table :data="tableData" border stripe style="width: 100%">
      <el-table-column prop="id" label="ID" width="180" sortable />
      <el-table-column prop="username" label="Username" width="180" sortable />
      <el-table-column prop="nickName" label="Nickname" sortable />
      <el-table-column prop="age" label="Age" sortable />
      <el-table-column prop="sex" label="Sex" sortable />
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
      <!-- 下面两行的报错似乎不影响整体 -->
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
    <div>
      <!-- 新增按钮的弹框 -->
      <el-dialog
        v-model="dialogVisible"
        title="Tips"
        width="30%"
        :before-close="handleClose"
      >
        <el-form :model="form" label-width="120px">
          <el-form-item label="Username">
            <!-- username和后端对应 -->
            <el-input v-model="form.username" style="width: 80%" />
          </el-form-item>
          <el-form-item label="Nickname">
            <el-input v-model="form.nickname" style="width: 80%" />
          </el-form-item>
          <el-form-item label="Age">
            <el-input v-model="form.age" style="width: 80%" />
          </el-form-item>
          <el-form-item label="Sex">
            <el-radio-group v-model="form.sex" class="ml-4">
              <el-radio label="1" size="large">Male</el-radio>
              <el-radio label="2" size="large">Female</el-radio>
              <el-radio label="3" size="large">Unknown</el-radio>
            </el-radio-group>
          </el-form-item>
          <el-form-item label="Address">
            <el-input
              type="textarea"
              v-model="form.address"
              style="width: 80%"
            />
          </el-form-item>
        </el-form>

        <!-- <span>This is a message</span> -->
        <template #footer>
          <span class="dialog-footer">
            <el-button @click="dialogVisible = false">Cancel</el-button>
            <el-button type="primary" @click="save_cors"> Confirm </el-button>
          </span>
        </template>
      </el-dialog>
    </div>
  </div>
</template>

<script scope>
import request from "@/utils/request";
import axios from "axios";
export default {
  name: "TableView",
  components: {},
  data() {
    return {
      form: {},
      dialogVisible: false,
      search: "",
      currentPage: 1,
      total: 10,
      tableData: [],
    };
  },
  methods: {
    add() {
      this.dialogVisible = true;
      this.form = {};
    },
    save() {
      request.post("/user", this.form).then((res) => {
        console.log(res);
      }); // 来自后端UserController.java里面的地址 //this.form是请求参数
      // 用axios实现数据交互
      this.dialogVisible = false;
    },
    save_cors() {
      // 另一种访问后端的方法
      // const _this = this;
      axios.get("http://localhost:9009/user/find").then(function (res) {
        ///console.log(resp.data);
        console.log(res);
        this.form = res.data;
        this.dialogVisible = false;
      });
    },
    handleEdit() {},
    handleDelete() {},
  },
};
// import { ref } from "vue";
// 表格数据
// const tableData = [
//   {
//     date: "2016-05-03",
//     name: "Tom",
//     address: "No. 189, Grove St, Los Angeles",
//   },
//   {
//     date: "2016-05-02",
//     name: "Tom",
//     address: "No. 189, Grove St, Los Angeles",
//   },
//   {
//     date: "2016-05-04",
//     name: "Tom",
//     address: "No. 189, Grove St, Los Angeles",
//   },
//   {
//     date: "2016-05-01",
//     name: "Tom",
//     address: "No. 189, Grove St, Los Angeles",
//   },
// ];
// const currentPage1 = ref(5);
// const currentPage2 = ref(5);
// const currentPage3 = ref(5);
// const currentPage4 = ref(4);
// const pageSize2 = ref(100);
// const pageSize3 = ref(100);
// const pageSize4 = ref(20);
// const small = ref(false);
// const background = ref(false);
// const disabled = ref(false);
// const handleSizeChange = (val: number) => {
//   console.log(`${val} items per page`);
// };
// const handleCurrentChange = (val: number) => {
//   console.log(`current page: ${val}`);
// };

// function add() {}
// function handleEdit() {}
</script>
