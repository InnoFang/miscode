/**
 * Created by InnF on 2018/4/12.
 */

import React from 'react'
import ReactDOM from 'react-dom'
import MediaQuery from 'react-responsive'
import {
    BrowserRouter as Router,
    Route,
    Link
} from 'react-router-dom'


import 'antd/dist/antd.css'

import PCIndex from './components/pc/pc_index'
import MobileIndex from './components/mobile/mobile_index'

export default class Root extends React.Component {
    render() {
        return (
            <div>
                <MediaQuery query='(min-device-width: 1224px)'>
                    <PCIndex style={require('./css/pc.css')}/>
                </MediaQuery>

                <MediaQuery query='(max-device-width: 1224px)'>
                    <MobileIndex style={require('./css/mobile.css')}/>
                </MediaQuery>

            </div>
        );
    };
}

ReactDOM.render(<Root />, document.getElementById('root'));
