// // NOTE 用于封装axios数据访问的插件
// // NOTE 前端跨域配置
// import axios from "axios";

// const request = axios.create({
//   baseURL: "/api", // NOTE 注意！！ 这里是全局统一加上了 "/api" 前缀，也就是说所有接口都会加上"/api"前缀在，页面里面写接口的时候就不要加 "/api"了，否则会出现2个"/api"，类似 "/api/api/user"这样的报错，切记！！！
//   timeout: 5000,
// });

// // request 拦截器
// // 可以自请求发送前对请求做一些处理
// // 比如统一加token，对请求参数统一加密
// request.interceptors.request.use(
//   (config) => {
//     config.headers["Content-Type"] = "application/json;charset=utf-8";
//     // config.headers["token"] = user.token;  // 设置请求头
//     return config;
//   },
//   (error) => {
//     return Promise.reject(error);
//   }
// );

// // response 拦截器
// // 可以在接口响应后统一处理结果
// request.interceptors.response.use(
//   (response) => {
//     let res = response.data;
//     // 如果是返回的文件
//     if (response.config.responseType === "blob") {
//       return res;
//     }
//     // 兼容服务端返回的字符串数据
//     if (typeof res === "string") {
//       res = res ? JSON.parse(res) : res;
//     }
//     return res;
//   },
//   (error) => {
//     console.log("err" + error); // for debug
//     return Promise.reject(error);
//   }
// );

// export default request;

// NOTE 后端跨域配置
// import axios from "axios";

// const request = axios.create({
//   baseURL: "http://localhost:9090/", // 注意！！ 这里是全局统一加上了 后端接口前缀 前缀，后端必须进行跨域配置！
//   timeout: 5000,
// });

// // request 拦截器
// // 可以自请求发送前对请求做一些处理
// // 比如统一加token，对请求参数统一加密
// request.interceptors.request.use(
//   (config) => {
//     config.headers["Content-Type"] = "application/json;charset=utf-8";

//     // config.headers["token"] = user.token;  // 设置请求头
//     return config;
//   },
//   (error) => {
//     return Promise.reject(error);
//   }
// );

// // response 拦截器
// // 可以在接口响应后统一处理结果
// request.interceptors.response.use(
//   (response) => {
//     let res = response.data;
//     // 如果是返回的文件
//     if (response.config.responseType === "blob") {
//       return res;
//     }
//     // 兼容服务端返回的字符串数据
//     if (typeof res === "string") {
//       res = res ? JSON.parse(res) : res;
//     }
//     return res;
//   },
//   (error) => {
//     console.log("err" + error); // for debug
//     return Promise.reject(error);
//   }
// );

// export default request;

// NOTE https://blog.csdn.net/weixin_44653261/article/details/118525450
// import axios from "axios";
// import { Message } from "element-plus";

// axios.interceptors.response.use(
//   //统一返回错误处理
//   (success) => {
//     //success.status是http返回的响应码，而success.data.status才是服务器真正返回的json
//     if (success.status && success.status == 200 && success.data.status == 500) {
//       Message.error({ message: success.data.msg });
//       return;
//     }
//     if (success.data.msg) {
//       Message.success({ message: success.data.msg });
//     }
//     return success.data;
//   },
//   (error) => {
//     if (error.response.status == 504 || error.response.status == 404) {
//       Message.error({ message: "服务器发生问题" });
//     } else if (error.response.status == 403) {
//       Message.error({ message: "权限不足，请联系管理员" });
//     } else if (error.response.status == 401) {
//       Message.error({ message: "尚未登录，请登录" });
//     } else {
//       if (error.response.data.msg) {
//         Message.error({ message: error.response.data.msg });
//       } else {
//         Message.error({ message: "未知错误！" });
//       }
//     }
//     return;
//   }
// );

// let base = ""; //加前缀直接修改base就够了
// export const postKeyValueRequest = (url, params) => {
//   return axios({
//     method: "post",
//     url: `${base}${url}`,
//     data: params,
//     transformRequest: [
//       function (data) {
//         let ret = "";
//         for (let i in data) {
//           ret +=
//             encodeURIComponent(i) + "=" + encodeURIComponent(data[i]) + "&";
//         }
//         console.log(ret);
//         return ret;
//       },
//     ],
//     headers: {
//       "Content-Type": "application/x-www-form-urlencoded",
//     },
//   });
// };
