<template>
    <div>
        <table>
            <tr>
                <td>ID</td>
                <td>NAME</td>
                <td>AUTHOR</td>
            </tr>
            <tr v-for="item in books" v-bind:key="item.id">
                <td>{{item.id}}</td>
                <td>{{item.name}}</td>
                <td>{{item.author}}</td>
            </tr>
        </table>
    </div>
</template>
 
<script>
 
import axios from 'axios'
export default {
    name:"Book",
    data(){
        return {
            books:[]
        }
    },
    created(){
        const _this = this
        axios.get( 'http://localhost:8181/book/findAll').then(function(resp){
            ///console.log(resp.data)
            _this.books = resp.data         
        })
        
       
    }
    
}
</script>
<style scoped>
 
</style>