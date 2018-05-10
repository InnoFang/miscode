/**
 * Created by InnF on 2018/4/12.
 */

import React from 'react'
import ReactDOM from 'react-dom'
import MediaQuery from 'react-responsive'
import {
    HashRouter as Router,
    Route,
    Link
} from 'react-router-dom'


import 'antd/dist/antd.css'

import PCIndex from './components/pc/pc_index'
import PCNewsDetails from './components/pc/pc_news_details'
import MobileIndex from './components/mobile/mobile_index'

import './css/pc.css';
import './css/mobile.css';

export default class Root extends React.Component {
    render() {
        return (
            <div>
                <MediaQuery query='(min-device-width: 1224px)'>
                    <Router>
                        <div>


                 、
                            3++++++++++++++++++++++++++++4456654<Route path="/" component={PCIndex}/>
                            <Route path="/details/:uniquekey/" component={PCNewsDetails}/>
                        </div>
                    </Router>
                </MediaQuery>

                <MediaQuery query='(max-device-width: 1224px)'>
                    <MobileIndex />
                </MediaQuery>

            </div>
        );
    };
}

ReactDOM.render(<Root />, document.getElementById('root'));
